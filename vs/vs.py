import pygame as pg
from map import Map
import sys

class Player():

    def __init__(self, name, sign, color):
        self.name = name
        self.sign = sign
        self.color = color
        self.score = 0

def get_name(str):
    if "./players/" in str:
        return str.split("/")[2].split('.')[0]
    elif 'players/' in str:
        return str.split("/")[1].split('.')[0]
    else:
        return str.split(".")[1][1:]

def draw_text(p1, p2, run, s, win):
    menu1 = font.render('SPACE - Start/Pause     N - Next move     ESC - Exit', 1, pg.Color("green"))
    win.blit(menu1, (s.screen_width / 2 - (menu1.get_width() / 2), 30))
    menu2 = font.render('(left/rigth arrow - pause/play music)', 1, pg.Color("green"))
    win.blit(menu2, (s.screen_width / 2 - (menu2.get_width() / 2), 90))
    name1 = font.render(p1.name, 1, pg.Color(p1.color))
    win.blit(name1, (50, 50))
    score1 = font.render(str(p1.score), 1, pg.Color(p1.color))
    win.blit(score1, (50, (name1.get_height() + 55)))
    name2 = font.render(p2.name, 1, pg.Color(p2.color))
    win.blit(name2, (s.screen_width - 50 - name2.get_width(), 50))
    score2 = font.render(str(p2.score), 1, pg.Color(p2.color))
    win.blit(score2, (s.screen_width - 50 - score2.get_width(), (name2.get_height() + 55)))
    if run == -1:
        winner = p1.name.upper() + ' WINS' if p1.score > p2.score else p2.name.upper() + ' WINS'
        end = font.render(winner, 1, pg.Color('orange'))
        win.blit(end, (s.screen_width / 2 - (end.get_width() / 2), 150))

# get players
input()
input()
input()
input()
input()
p1 = Player(get_name(input().split()[1]), 'o', "red")
input()
p2 = Player(get_name(input().split()[1]), 'x', "blue")
input()

#get window
# win = pg.display.set_mode((0, 0), pg.HWSURFACE|pg.FULLSCREEN)
win = pg.display.set_mode((0, 0), pg.RESIZABLE)
pg.display.set_caption("Filler")
pg.font.init()
pg.mixer.init()
pg.mixer.music.load('./vs/Endless.mp3')
pg.mixer.music.play(-1)
font = pg.font.Font(None, 60)

# get map
map_size = input().split()
map = Map(map_size[1], map_size[2][:2], win)
map.read_map(p1, p2)

#start game
run = 0
next = 0
end = 0
while True:
    if next:
        run = 0
        next = 0
    for event in pg.event.get():
        if event.type == pg.QUIT:
            sys.exit()
        elif event.type == pg.KEYDOWN:
            if event.key == pg.K_ESCAPE:
                sys.exit()
            elif event.key == pg.K_LEFT:
                pg.mixer.music.pause()
            elif event.key == pg.K_RIGHT:
                pg.mixer.music.unpause()
            elif event.key == pg.K_SPACE:
                run = 0 if run else 1
            elif event.key == pg.K_n:
                if run == 0:
                    run = 1
                    next = 1
    win.fill(pg.Color("white"))
    draw_text(p1, p2, run, map, win)
    map.draw_map(p1, p2, win)
    pg.display.flip()
    if run == 1:
        run = map.read_map(p1, p2)
    if run == -1:
        if end == 0:
            pg.mixer.music.stop()
            pg.mixer.Sound('./vs/Game Over.wav').play()
            end = 1