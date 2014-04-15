import time

class Grid:

  def __init__(self, width, height):
    self.grid = [['.' for y in range(0, height)] for x in range(0, width)]
    self.width = width
    self.height = height

  def horizontalLine(self, x, y, width):
    for i in range(0, width):
      self.grid[x + i][y] = 'W'

  def verticalLine(self, x, y, height):
    for i in range(0, height):
      self.grid[x][y + i] = 'W'

  def findPath(self, p1, p2):
    queue = []
    dists = [[None for y in range(0, self.height)] for x in range(0, self.width)]
    dists[0][0] = 0
    prev = [[None for y in range(0, self.height)] for x in range(0, self.width)]

    for x in range(0, self.width):
      for y in range(0, self.height):
        if self.grid[x][y] != 'W':
          queue.append({"x": x, "y": y})

    while len(queue):
      shortest = None
      for i in queue:
        if shortest == None and dists[i["x"]][i["y"]] != None:
          shortest = i
        else:
          if dists[i["x"]][i["y"]] != None and dists[i["x"]][i["y"]] < dists[shortest["x"]][shortest["y"]]:
            shortest = i

      if shortest == None:
        break;


      queue.remove(shortest)

      x = shortest["x"]
      y = shortest["y"]

      self.grid[x][y] = ' ' # Set as visited

      alt = dists[shortest["x"]][shortest["y"]] + 1

      # Right
      if x + 1 < self.width and self.grid[x + 1][y] != 'W':
        if dists[x + 1][y] == None or alt < dists[x + 1][y]:
          dists[x + 1][y] = alt
          prev[x + 1][y] = shortest

      # Left
      if x - 1 >= 0 and self.grid[x - 1][y] != 'W':
        if dists[x - 1][y] == None or alt < dists[x - 1][y]:
          dists[x - 1][y] = alt
          prev[x - 1][y] = shortest

      # Top
      if y + 1 < self.height and self.grid[x][y + 1] != 'W':
        if dists[x][y + 1] == None or alt < dists[x][y + 1]:
          dists[x][y + 1] = alt
          prev[x][y + 1] = shortest

      # Bottom
      if y - 1 >= 0 and self.grid[x][y - 1] != 'W':
        if dists[x][y - 1] == None or alt < dists[x][y - 1]:
          dists[x][y - 1] = alt
          prev[x][y - 1] = shortest

    p = prev[p2["x"]][p2["y"]]
    while p != None:
      self.grid[p["x"]][p["y"]] = '*'
      p = prev[p["x"]][p["y"]]

    self.grid[p1["x"]][p1["y"]] = 'S'
    self.grid[p2["x"]][p2["y"]] = 'F'


  def __str__(self):
    s = ""
    for y in range(self.height):
      for x in range(self.width):
        s += self.grid[x][y] + " "
      s += "\n"
    return s

