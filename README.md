# Smart-Bartender
> TODO

## Table of Contents
- [System Overview](#system-overview)
- [Hardware Setup](#hardware-setup)

## System Overview
> TODO - Include the diagram that was drawn the other day

## Hardware Setup
> TODO

## Installation of Tesseract - for Windows 
- Download .exe from https://github.com/UB-Mannheim/tesseract/wiki
- Go to Environment variable (Reach there by just searching it in the start menu or Go to Control Panel > System > Advanced System Settings > Environment Variables) and add the path where tesseract is installed (Usually C:\Program Files\Tesseract-OCR)
- Find script file pytesseract.py from C:\Users\User\Anaconda3\Lib\site-packages\pytesseract and open it. Change the following code from tesseract_cmd = 'tesseract' to: tesseract_cmd = 'C:/Program Files/Tesseract-OCR/tesseract.exe'
- pip install pytesseract | conda install -c conda-forge pytesseract
- run the code using command 'python preprocessing.py --image /path to image of your choice --east frozen_east_text_detection.pb'