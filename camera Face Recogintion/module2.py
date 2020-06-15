# -*- coding: utf-8 -*-
"""
Created on Fri Mar 15 08:52:09 2019

@author: Namratesh
"""

import cv2
import os
import numpy as np
from os import listdir
from os.path import isfile, join

data_path = 'C:/Users/Namratesh/Desktop/major/camera fr/dataset/'
onlyFiles = [f for f in listdir(data_path) if isfile(join(data_path, f))]

Training_Data, Labels = [],[]

for i, files in enumerate(onlyFiles):
    image_path = data_path + onlyFiles[i]
    images = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    Training_Data.append(np.asarray(images, dtype=np.uint8))
    Labels.append(i)

Labels = np.asarray(Labels, dtype=np.int32)


recognizer = cv2.face.LBPHFaceRecognizer_create()

recognizer.train(np.asarray(Training_Data), np.asarray(Labels))

print('Model Training Complete')