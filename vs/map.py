import pygame as pg

class Map():

    def __init__(self, rows, columns, win):
        self.rows = int(rows)
        self.columns = int(columns)
        self.map = [[0 for j in range(self.columns)] for i in range(self.rows)]
        self.screen_width =  win.get_rect().width
        self.screen_height = win.get_rect().height
        self.block_size = (self.screen_height - 220) // self.rows
        self.map_x = (self.screen_width - self.block_size * self.columns) // 2
        self.map_y = self.screen_height - self.block_size * self.rows - 30

    def draw_map(self, p1, p2, win):
        for i in range(self.rows):
            pg.draw.line(win, pg.Color('white'), [self.map_x, self.map_y + i * self.block_size],
                [self.map_x + self.block_size * self.columns, self.map_y + i * self.block_size])
            for j in range(self.columns):
                color = "black"
                if self.map[i][j] == p1.sign.upper():
                    color = p1.color
                elif self.map[i][j] == p1.sign:
                    color = "orange"
                elif self.map[i][j] == p2.sign.upper():
                    color = p2.color
                elif self.map[i][j] == p2.sign:
                    color = "blueviolet"
                pg.draw.rect(win, pg.Color(color), (self.map_x + j * self.block_size + 1,
                                                    self.map_y + i * self.block_size + 1,
                                                    self.block_size,
                                                    self.block_size))
                pg.draw.line(win, pg.Color("white"), [self.map_x + j * self.block_size, self.map_y],
                       [self.map_x + j * self.block_size, self.map_y + self.block_size * self.rows])

    def read_map(self, p1, p2):
        input()
        count = True
        for i in range(self.rows):
            line = input().split()
            if int(line[0]) == i:
                for j in range(len(line[1])):
                    self.map[i][j] = line[1][j]
                    if line[1][j] == p1.sign:
                        if count:
                            p1.score += 1
                            count = False
                    if line[1][j] == p2.sign:
                        if count:
                            p2.score += 1
                            count = False
        piece = input().split()
        n = int(piece[1])
        for i in range(n):
            input()
        input()
        s = input()
        if "==" in s:
            input()
            return -1
        if "Piece" in s:
            for i in range(int(s.split()[1])):
                input()
            input()
            input()
        return 1