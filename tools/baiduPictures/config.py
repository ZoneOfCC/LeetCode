import os

POOLNUM = 4

MAX = 1000

BASE = 'res'

BUILDING = os.path.join(BASE, 'building')

PEOPLE = os.path.join(BASE, 'people')

SCENERY = os.path.join(BASE, 'scenery')

FLOWER = os.path.join(BASE, 'flower')

CAR = os.path.join(BASE, 'car')

URL = r"http://image.baidu.com/search/acjson?tn=resultjson_com&ipn=rj&ct=201326592&fp=result&queryWord={word}&" \
      r"cl=2&lm=-1&ie=utf-8&oe=utf-8&st=-1&ic=0&word={word}&face=0&istype=2nc=1&pn={pn}&rn=60"

PIC_TYPES = {
    '建筑': BUILDING,
    '人脸': PEOPLE,
    '风景': SCENERY,
    '花': FLOWER,
    '汽车图片': CAR,
             }

STR_TABLE = {
    '_z2C$q': ':',
    '_z&e3B': '.',
    'AzdH3F': '/'
}

char_table = {
    'w': 'a',
    'k': 'b',
    'v': 'c',
    '1': 'd',
    'j': 'e',
    'u': 'f',
    '2': 'g',
    'i': 'h',
    't': 'i',
    '3': 'j',
    'h': 'k',
    's': 'l',
    '4': 'm',
    'g': 'n',
    '5': 'o',
    'r': 'p',
    'q': 'q',
    '6': 'r',
    'f': 's',
    'p': 't',
    '7': 'u',
    'e': 'v',
    'o': 'w',
    '8': '1',
    'd': '2',
    'n': '3',
    '9': '4',
    'c': '5',
    'm': '6',
    '0': '7',
    'b': '8',
    'l': '9',
    'a': '0'
}

CHAR_TABLE = {ord(key): ord(value) for key, value in char_table.items()}


# deal pics

SIZE = (256, 256)