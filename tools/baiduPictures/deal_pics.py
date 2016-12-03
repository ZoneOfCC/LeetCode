import os
import sys
import time
from config import *
from PIL import Image
from multiprocessing import Pool


def run(input):
    output = os.path.join(input, 'small')
    if not os.path.exists(output):
        os.makedirs(output)

    pics = os.listdir(input)
    for pic in pics:
        try:
            in_pic = os.path.join(sys.path[0], input, pic)
            output_pic = os.path.join(sys.path[0], output, pic)
            im = Image.open(in_pic)
            new_img = im.resize(SIZE, Image.ANTIALIAS)

            new_img.save(output_pic, quality=100)
        except:
            print("Error When Deal: ", in_pic)
            os.remove(in_pic)




if __name__ == '__main__':
    p = Pool(processes=POOLNUM)
    for name, dir in PIC_TYPES.items():
        print(name, dir)
        p.apply_async(run, (dir,))
    print('Waiting for all subprocesses done...')
    p.close()
    p.join()
    print('All subprocesses done.')