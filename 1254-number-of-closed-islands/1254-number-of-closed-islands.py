class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    island = self.nieghbors(grid, [i,j], True)
                    if island:
                        count = count + 1
        return count

    def nieghbors(self, grid: list[list[int]], pos: list[int], island: bool) -> bool:
        grid[pos[0]][pos[1]] = 2

        if pos[0] == 0:
            island = False
        elif grid[pos[0] - 1][pos[1]] == 0:
            island = self.nieghbors(grid, [pos[0] - 1,pos[1]], island)
        if pos[0] == len(grid) - 1:
            island = False
        elif grid[pos[0] + 1][pos[1]] == 0:
            island = self.nieghbors(grid, [pos[0] + 1,pos[1]], island)
        if pos[1] == 0:
            island = False
        elif grid[pos[0]][pos[1] - 1] == 0:
            island = self.nieghbors(grid, [pos[0],pos[1] - 1], island)
        if pos[1] == len(grid[0]) - 1:
            island = False
        elif grid[pos[0]][pos[1] + 1] == 0:
            island = self.nieghbors(grid, [pos[0],pos[1] + 1], island)

        return island