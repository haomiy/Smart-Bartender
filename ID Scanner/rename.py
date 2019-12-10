
import os
import numpy as np

dir = "./WA_License/"
files = os.listdir(dir)
cnt = 0

for file in files:
    print(cnt)
    
#   if file.endswith(".jpg") or file.endswith(".png") or file.endswith(".jpeg"):
        # read img
    file_new = "license" + str(cnt) + ".jpg"
    os.rename(dir + file, dir + file_new)
    
    cnt = cnt + 1
