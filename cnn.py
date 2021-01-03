
import numpy as np
from tensorflow import keras
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Dense, Flatten, Dropout
from tensorflow.keras.utils import to_categorical

def model():
    # Download data
    mnist = keras.datasets.mnist
    print(type(mnist))
    (train_images, train_labels), (test_images, test_labels) = mnist.load_data()
    # Normalize
    train_images = (train_images / 255) - 0.5
    test_images = (test_images / 255) - 0.5
    # Reshape
    train_images = np.expand_dims(train_images, axis=3)
    test_images = np.expand_dims(test_images, axis=3)
    # Build model
    model = Sequential([
        Conv2D(8, 3, input_shape=(28, 28, 1),padding='same',activation='relu'),
        MaxPooling2D(pool_size=2),
        Dropout(0.25),

        Conv2D(32, 3,padding='same', activation='relu'),
        MaxPooling2D(pool_size=2),
        Dropout(0.25),

        Flatten(),
        Dense(512, activation='relu'),
        Dropout(0.25),
        Dense(10, activation='softmax'),
    ])
    # Compile model
    model.compile(
        optimizer = keras.optimizers.Adam(learning_rate = 0.01),
        loss='categorical_crossentropy',
        metrics=['accuracy'],
    )
    # Train model
    model.fit(
        train_images,
        to_categorical(train_labels),
        epochs=2,
        validation_data=(test_images, to_categorical(test_labels)),
    )
    return model

def predict(model, data):
    prediction = model.predict(data)
    return np.argmax(prediction[0])

