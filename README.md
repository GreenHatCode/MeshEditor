# MeshEditor
This project is a simple console application that processes input and output ASCII STL files.

## Table of Contents

- [About](#about)
- [Installation](#installation)
- [Available options](#available-options)
- [Credit](#credit)

## About

This project is a console application that processes input and output ASCII STL files. The application can generate tessellated cubes, spheres and split objects. 

## Installation

### Prerequisites

- C++14 or above
- Microsoft Visual Studio 2019 or newer

### Steps

1. Clone the repository:
    ```bash
    git clone https://github.com/GreenHatCode/MeshEditor.git
    ```
2.  Change git remote url to avoid accidental pushes to base project
    ```bash
    git remote set-url origin github_username/repo_name
    git remote -v # confirm the changes
    ```
3. Open the solution in Microsoft Visual Studio (open file MeshEditor.sln)
4. Compile the project under x86, select debug.
5. To run project:
   - Open developer command prompt or cmd.
   - Run compiled application with necessary command.
   ```
    MeshEditor.exe Cube L = 10.0, origin = (4.5,3.4,2.1), filepath = "D:\cube.stl"
   ```

## Available options
There are 3 commands implemented in the application. The command description, syntax, example and exit codes are listed here.

### Cube
This command outputs a tessellated cube to the ASCII STL file. 

Command syntax:
```
Cube L = dbl_value, origin = (dbl_value, dbl_value, dbl_value), filepath = "string_value"
```

Command parameters:

  - **L** - the length of the cube side.

  - **origin** - the position of the cube in a scene where commas separate the coordinates with or without white spaces.

  - **filepath** - the full path to the output STL file including its name.

Example:
```
Cube L = 10.0, origin = (4.5,3.4,2.1), filepath = "D:\cube.stl"
```

Exit codes:
  - 0 - if successed.
  - 1 - if **L** <= 0.
  - 2 - if the **filepath** is incorrect.
  - 3 - if one or all arguments are not specified.

### Sphere
This command outputs a tessellated sphere to the ASCII STL file. 

Command syntax:
```
Sphere R = dbl_value, origin = (dbl_value, dbl_value, dbl_value), slices = uint_value, rings = uint_value, filepath = "string_value"
```

Command parameters:

  - **R** - the radius of the sphere.

  - **origin** - the position of the cube in a scene where commas separate the coordinates with or without white spaces.

  - **slices** - number of vertical segments that like meridians converge to the north and south poles of the Earth.

  - **rings** - number of horizontal segments that cut the sphere like parallels cut the Earth.
  
  - **filepath** - the full path to the output STL file including its name.

Example:
```
Sphere R = 10.0, origin = (4.5,3.4,2.1), slices = 30, rings = 40, filename = "D:\sphere.stl"
```

Exit codes:
  - 0 - if successed.
  - 1 - if **R** <= 0.
  - 2 - if **slices** <= 2 or **rings** <= 1.
  - 3 - if the **filepath** is incorrect.
  - 4 - if one or all arguments are not specified.

### Split
This command outputs two tessellated meshes to the **output1** and **output2** STL ASCII files as the output of splitting the original mesh contained in the **input** file by the plane difined by the normal vector from the **origin** in the **direction**.

Command syntax:
```
Split input = "string_value", origin = (dbl_value, dbl_value, dbl_value), direction = (dbl_value, dbl_value, dbl_value), output1 = "string_value", output2 = "string_value"
```

Command parameters:

  - **input** - the full path to the input STL file including its name containing an original tessellated mesh.
  - **origin** - the positi0n of the normal vector start in the 3D scene where commas separate the coordinates with or without white spaces.
  - **direction** - the position of the normal vector direction in the 3D scene where commas separate the coordinates with or without white spaces.
  - **output1**, **output2** - the full path to output STL files including their names.

Example:
```
Split input = "D:\sphere.stl", origin = (1,2,3), direction = (0,0,1), output1 = "D:\above_the_plane.stl", output2 = "D:\under_the_plae.stl"
```

Exit codes:
  - 0 - if successed.
  - 1 - if a normal length <= 0.
  - 2 - if **input**, **output1** or **output2** is incorrect.
  - 3 - if one or all arguments are not specified.
  - 4 - if the plane doesn't intersect the original mesh, which becomes the result.


## Credit
Here you can find links to projects which I've used in GraphApp
- STL parser [link to GitHub repository](https://github.com/elerac/stl-creator)

