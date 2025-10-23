import curses
import random
import time

# Initialize the screen
screen = curses.initscr()
curses.curs_set(0)  # Hide cursor
height, width = screen.getmaxyx()
window = curses.newwin(height, width, 0, 0)
window.keypad(1)
window.timeout(100)  # Refresh every 100 ms

# Initial snake position and body
snake_x = width//4
snake_y = height//2
snake = [
    [snake_y, snake_x],
    [snake_y, snake_x-1],
    [snake_y, snake_x-2]
]

# Initial food position
food = [random.randint(1, height-2), random.randint(1, width-2)]
window.addch(food[0], food[1], curses.ACS_PI)

# Initial direction (right)
key = curses.KEY_RIGHT

score = 0

while True:
    next_key = window.getch()
    key = key if next_key == -1 else next_key

    # Calculate new head position
    head = snake[0].copy()

    if key == curses.KEY_DOWN:
        head[0] += 1
    elif key == curses.KEY_UP:
        head[0] -= 1
    elif key == curses.KEY_LEFT:
        head[1] -= 1
    elif key == curses.KEY_RIGHT:
        head[1] += 1
    else:
        # Ignore other keys
        continue

    # Check collision with boundaries
    if head[0] in [0, height] or head[1] in [0, width] or head in snake:
        curses.endwin()
        print(f"Game Over! Your score: {score}")
        break

    # Insert new head to snake
    snake.insert(0, head)

    # Check if food eaten
    if head == food:
        score += 1
        food = None
        while food is None:
            nf = [random.randint(1, height-2), random.randint(1, width-2)]
            if nf not in snake:
                food = nf
        window.addch(food[0], food[1], curses.ACS_PI)
    else:
        # Remove tail
        tail = snake.pop()
        window.addch(tail[0], tail[1], ' ')

    # Draw snake head
    window.addch(snake[0][0], snake[0][1], curses.ACS_CKBOARD)
