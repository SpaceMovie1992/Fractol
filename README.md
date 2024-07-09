# Fractol

## Description

Fractol is a small fractal exploration program that allows you to explore and visualize different fractals, specifically the Julia set and the Mandelbrot set. The program is implemented using the MiniLibX library and provides smooth interaction through mouse and keyboard controls.

## Features

- Display the Julia set and Mandelbrot set fractals.
- Zoom in and out using the mouse wheel.
- Create different Julia sets by passing different parameters.
- Display a list of available parameters and exit properly if no or invalid parameters are provided.
- Use colors to show the depth of each fractal with potential for psychedelic effects.
- Smooth window management (minimize, change focus, etc.).
- Clean exit by pressing ESC or clicking the window's close button.

## Bonus Features

- Additional fractal types beyond Julia and Mandelbrot sets.

## Usage

### Compiling the Program

To compile the program, run the following command:

```sh
make

To run the program, use the following command:

./fractol [fractal_type] [options]
fractal_type: The type of fractal to display.
Supported types are:
                      mandelbrot
                      julia

Controls
* Use the mouse wheel to zoom in and out.
* Press ESC to close the window and quit the program.
* Click the window's close button to quit the program cleanly.
Dependencies
* MiniLibX library
* Math library (-lm compiler option)
* Standard C libraries (open, close, read, write, malloc, free, perror, strerror, exit)
* Custom ft_printf function or equivalent
Makefile Targets
* all: Compile the program.
* clean: Remove object files.
* fclean: Remove object files and the executable.
* re: Recompile the program.
External Functions Used
* open
* close
* read
* write
* malloc
* free
* perror
* strerror
* exit
All functions from the math library (-lm compiler option)
All functions from the MiniLibX library
ft_printf or any equivalent custom function
Author
This project was created by Ana Husic.
