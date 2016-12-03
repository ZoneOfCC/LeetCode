import os
from config import *
from PIL import Image

in_pic = os.path.join(CAR, 'small',)
for i in range(1, 999):
    try:
        print(i)
        im = Image.open(os.path.join(in_pic, str(i) + '.jpg'))
        print(im.size)
        print('%' * 50)
        # for h in range(im.size[0]):
        #     for w in range(im.size[1]):
        #         pixel = im.getpixel((w, h))
        #         print(pixel)
        #     print('')
    except:
        print('Error')

