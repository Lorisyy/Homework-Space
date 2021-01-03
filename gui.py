import numpy as np
from tkinter import *
from tkinter import messagebox 
from PIL import ImageGrab, Image, ImageFilter, ImageOps
from cnn import *
import matplotlib.pyplot as plt


class Paint():
    def __init__(self, root):
        self.root = root
        # Initialize indow
        self.root.title("Hand Write")
        self.root.geometry("400x320")
        self.root.configure(background='white')
        self.root.resizable(0, 0)
        # Button wigdets
        self.guess_button = Button(self.root, text="Go", bd=4, bg='white', command=self.get_data, height = 1,width=5, relief=RIDGE)
        self.guess_button.place(x=0,y=30)
        self.clear_button = Button(self.root, text="Clear", bd=4, bg='white', command=self.clear, height = 1,width=5, relief=RIDGE)
        self.clear_button.place(x=0,y=70)
        
        # Paint canvas
        self.canvas = Canvas(self.root, bg='white',bd=2,relief=GROOVE,height=300,width=300)
        self.canvas.place(x=80,y=0)
        # Bind brush to canvas
        self.lastx, self.lasty = None, None
        self.listx, self.listy = [], []
        self.canvas.bind('<1>', self.activate_paint)

    def activate_paint(self, event):
        self.canvas.bind('<B1-Motion>', self.paint)
        self.lastx, self.lasty = event.x, event.y

    def paint(self, event):
        x, y = event.x, event.y
        self.canvas.create_line((self.lastx, self.lasty, x, y), width=20, capstyle=ROUND)
        self.lastx, self.lasty = x, y
        self.listx.append(self.lastx)
        self.listy.append(self.lasty)

    def clear(self):
        self.canvas.delete("all")
        self.listx.clear()
        self.listy.clear()

    def get_data(self):
        # Grab image from canvas
        x = self.root.winfo_rootx() + self.canvas.winfo_x() + (min(self.listx) - 20)
        y = self.root.winfo_rooty() + self.canvas.winfo_y() + (min(self.listy) - 20)
        x_max = self.root.winfo_rootx() + self.canvas.winfo_x() + max(self.listx) + 20 
        y_max = self.root.winfo_rooty() + self.canvas.winfo_y() + max(self.listy) + 20 
        im = ImageGrab.grab().crop((x,y,x_max,y_max))
        im = im.resize((20,20), resample=Image.ANTIALIAS).filter(ImageFilter.SHARPEN)
        print(type(im))
        print(im.mode)
        im = im.convert('L')
        print(im.mode)
        im = ImageOps.invert(im)
        
        plt.imshow(im)
        # Paste image onto 28x28 white canvas to replicate MNIST
        newIm = Image.new('L', (28, 28))
        newIm.paste(im, (4, 4))
        # Extract and normailise pixel data as np array
        data = np.array(newIm)
        data =  (data / 255) - 0.5
        data = np.expand_dims(np.expand_dims(data, 0),axis=3)
        # Predict
        prediction = predict(model,data)
        messagebox.showinfo("", "According to the input, you've wrote the number " + str(prediction))
        # Clear canvas
        self.canvas.delete("all")
        self.listx.clear()
        self.listy.clear()
   
if __name__=="__main__":
    model = model()
    root = Tk()
    p = Paint(root)
    root.mainloop()
