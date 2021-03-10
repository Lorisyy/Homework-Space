import sys
reload(sys)
sys.setdefaultencoding('utf-8')

from PIL import Image
from PIL import ImageEnhance
from PIL import ImageFilter
import cv2
import time
time1 = time.time()

def img_zip(path,filename1,filename2):
  image = cv2.imread(path+filename1)
  res = cv2.resize(image, (1280, 960), interpolation=cv2.INTER_AREA)
  cv2.imwrite(path+filename2, res)
  imgE = Image.open(path+filename2)
  imgEH = ImageEnhance.Contrast(imgE)
  img1 = imgEH.enhance(2.8)
  gray1 = img1.convert("L")
  gary2 = gray1.filter(ImageFilter.DETAIL)
  gary3 = gary2.point(lambda i: i * 0.9)
  gary3.save(path+filename2)

if __name__ == '__main__':
  path="/Users/mac/Desktop"
  filename1="Touxiang.png"
  filename2="Touxiang_C.png"
  img_zip(path,filename1,filename2)
  time2 = time.time()
  print ('Total:' + str(time2 - time1) + 's')
