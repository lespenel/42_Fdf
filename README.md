## FDF - Wireframe Model of a 3D Landscape

<td><image src="./screenshot/t1.png"></image></td>

FDF is a project aimed at creating a wireframe model of a 3D landscape.
This project introduces the basics of computer graphics programming using the MiniLibX library, Bresenham's line algorithm, transformation matrix, focusing on rendering and managing 3D scenes in C.

## Usage

**Run the Binary**: Execute the `fdf` binary with an `.fdf` file as a parameter. This file should contain the coordinates of the landscape to be rendered.

## Controls

### Translation
- **Up Arrow**: Move the model up
- **Down Arrow**: Move the model down
- **Left Arrow**: Move the model left
- **Right Arrow**: Move the model right


### Rotation

- **Numpad 2**: Rotate around the X-axis (downwards)
- **Numpad 8**: Rotate around the X-axis (upwards)
- **Numpad 4**: Rotate around the Y-axis (left)
- **Numpad 6**: Rotate around the Y-axis (right)
- **Numpad 7**: Rotate around the Z-axis (counterclockwise)
- **Numpad 9**: Rotate around the Z-axis (clockwise)

### Scaling
- **Z**: Scale up the model
- **S**: Scale down the model

### Adjusting the Height of Z Vertices
- **+**: Increase the height of the Z vertices
- **-**: Decrease the height of the Z vertices

### Changing the Projection
- **P**: Change the projection (from isometric to weak projection)

### Quit
- **Escape**: Close the window and quit the application
