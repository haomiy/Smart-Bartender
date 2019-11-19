
import os
import numpy as np

files = os.listdir("./")
cnt = 0

for file in files:
    print(cnt)
    
    if file.endswith(".jpg") or file.endswith(".png"):
        # read img
        file_new = "License" + str(cnt) + ".jpg"
        os.rename(file, file_new)
        cnt = cnt + 1
