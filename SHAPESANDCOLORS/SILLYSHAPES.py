import random
from graphics import*
win = GraphWin('silly shapes', 600, 600)
for x in range(15):
  for i in range(10):

    r = random.randrange(256)
    b = random.randrange(256)
    g = random.randrange(256)
    color = color_rgb(r, g, b)

    t = random.randrange(256)
    h = random.randrange(256)
    n = random.randrange(256)
    color1 = color_rgb(t, h, n)

    y = random.randrange(256)
    j = random.randrange(256)
    m = random.randrange(256)
    color2 = color_rgb(y, j, m)

    e = random.randrange(256)
    d = random.randrange(256)
    c = random.randrange(256)
    color3 = color_rgb(e, d, c)

    pt = Point(40 + 40 * x, i * 60)
    cir = Circle(pt, 50)
    cir1 = Circle(pt, 40)
    cir2 = Circle(pt, 30)
    cir3 = Circle(pt, 20)
    cir.setOutline(color3)
    cir.setFill(color)
    cir1.setOutline(color2)
    cir1.setFill(color1)
    cir2.setOutline(color1)
    cir2.setFill(color2)
    cir3.setOutline(color)
    cir3.setFill(color3)
    cir.draw(win)
    cir1.draw(win)
    cir2.draw(win)
    cir3.draw(win)

win.getMouse()