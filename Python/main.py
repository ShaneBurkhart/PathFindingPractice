from grid import Grid

def main():
  g = Grid(50, 30)

  g.horizontalLine(0, 3, 4)
  g.horizontalLine(5, 3, 45)

  g.horizontalLine(0, 6, 40)
  g.horizontalLine(41, 6, 9)

  g.horizontalLine(0, 9, 20)
  g.horizontalLine(21, 9, 29)

  g.horizontalLine(0, 20, 29)
  g.verticalLine(21, 20, 10)

  g.findPath({"x": 0, "y": 0}, {"x": 49, "y": 29})

  print g


if __name__ == "__main__":
  main();
