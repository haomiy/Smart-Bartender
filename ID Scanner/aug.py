import os
import numpy as np
import cv2

raw_data_path = "./WA_License/"
save_data_path = "./dataset/images/"

files = os.listdir(raw_data_path)
cnt = 0
for file in files:

    print(file)
    # read image 
    im = cv2.imread(os.path.join(raw_data_path, file))
    H, W = im.shape[:2]
    
    cv2.imwrite(os.path.join(save_data_path, file), im)

    Naug = 3
    for i in range(Naug):
        # random scale
        scalex = np.random.randint(11)*0.1*0.6+0.7
        scaley = scalex*(np.random.randint(11)*0.1*0.6+0.7)
        
        im1 = cv2.resize(im,None,fx=scalex,fy=scaley)
        #label1 = cv2.resize(label,None,fx=scalex,fy=scaley,interpolation=cv2.INTER_NEAREST)
        H1, W1 = im1.shape[:2]

        # random crop if too large
        if H1>H:
            y0 = np.random.randint(0,H1-H)
            im1 = im1[y0:y0+H,:,:]
        if W1>W:
            x0 = np.random.randint(0,W1-W)
            im1 = im1[:,x0:x0+W,:]
        H1,W1 = im1.shape[:2]

        # pad if smaller
        x0 = (W-W1)//2
        y0 = (H-H1)//2
        im2 = np.zeros_like(im)
        im2[y0:y0+H1,x0:x0+W1,:]=im1

        cv2.imwrite(os.path.join(save_data_path,file[:-4]+'_scaled'+str(i)+".jpg"), im2)

