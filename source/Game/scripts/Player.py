import embed

def update (my_player : embed.Player):
    my_player.maxHorizontalSpeed = 0.25
    my_player.maxVerticalSpeed = 5.0
    my_player.jumpForce = 1.0
    my_player.maxShootTimer = 0.5
    my_player.maxReloadTimer = 4.0

    my_player.kForward = ord("W")
    my_player.kLeft = ord("A")
    my_player.kBackward = ord("S")
    my_player.kRight = ord("D")
    my_player.kReload = ord("R")