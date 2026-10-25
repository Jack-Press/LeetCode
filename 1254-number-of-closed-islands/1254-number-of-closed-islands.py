class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        columns = len(grid[0])
        res = 0

        def fill_island(row, column):
            if row < 0 or column < 0 or row >= rows or column >= columns or grid[row][column] == 1:
                return

            grid[row][column] = 1

            fill_island(row + 1, column)
            fill_island(row - 1, column)
            fill_island(row, column + 1)
            fill_island(row, column - 1)
        
        col = columns - 1
        for row in range(rows):
            if grid[row][0] == 0:
                fill_island(row, 0)
            if grid[row][col] == 0:
                fill_island(row, col)

        ro = rows - 1
        for column in range(columns):
            if grid[0][column] == 0:
                fill_island(0, column)
            if grid[ro][column] == 0:
                fill_island(ro, column)
        
        for row in range(1, ro):
            for column in range(1, col):
                if grid[row][column] == 0:
                    res += 1
                    fill_island(row, column)
        return res