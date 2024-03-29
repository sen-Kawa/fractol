# fractol
## Computer Graphics Fractals

### To compile fractol:
- `make`

### Executable:
- `./fractol Julia`
- `./fractol Mandelbrot`
- `./fractol --help`

### Keyboard and mouse events during runtime:
- `ESC`: exits the program in a clean way
- `i`: zoom in
- `o`: zoom out
- `p`: change in color range
- `m`: change in color range
- `Arrow left`: move view to the left
- `Arrow right`: move view to the right
- `Arrow up`: move view up
- `Arrow down`: move view down
- `Scroll in`: zoom in
- `Scroll out`: zoom out
- `Mouse move`: only available for Julia set, re-renders image with different parameters. (on low iterations for saving resources, iterations can be increased in header file)

### Graphics library used:
- miniLibx (https://github.com/42Paris/minilibx-linux)

### To compile miniLibx:
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#installation

### Submodules:
- Libft
> Before cloning repository:
- `git clone --recurse-submodules https://github.com/sen-Kawa/fractol.git`
> After cloning repository and not having used `--recurse-submodules`:
- `git submodule init`
- `git submodule update`

### Program's OS Compatibility:
- Linux

---
`./fractol Mandelbrot`
![image](https://user-images.githubusercontent.com/71138634/215203376-76a63d84-ad9c-48b2-83cc-701b00c4e199.png)

