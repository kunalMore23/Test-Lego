# Project Testing README

## Overview

Welcome to the 3D Model Sorter project's testing documentation. In this project, dynamic linking libraries (DLLs) have been developed to handle geometric information. Each DLL is associated with a specific testing method designed to evaluate the functionality of the classes within that library.

## Geometry.lib

### Point2D

The `Point2D` class encompasses the following features:

- Parameterized constructor
- Non-parameterized constructor
- Two member variables
- Getters and setters

**Testing:**
Tests are conducted on both constructors and getters/setters, using both default and specified values.

### Point3D

The `Point3D` class shares similarities with `Point2D`:

- Parameterized constructor
- Non-parameterized constructor
- Three member variables
- Corresponding getters and setters

**Testing:**
Similar to `Point2D`, testing involves both constructors and getters/setters, utilizing default and provided values.

### Triangle

The `Triangle` class includes:

- Parameterized constructor
- Non-parameterized constructor
- Three member variables of type `Point`

**Testing:**
Testing encompasses all constructors and getter-setters for comprehensive evaluation.

### Triangulation

The `Triangulation` class features:

- Parameterized constructor
- Getter method: "getTriangles()"

**Testing:**
Testing focuses on both the constructor and the getter method.

**Note:** Both `Point2D` and `Point3D` entities implement operator overloading, enabling the testing code to effectively compare two points.

## LegoShapeFactory.lib

The `LegoShapeFactory` serves as a foundational class for various Lego shapes, including:

- Cross
- Cube
- CuboQuarto
- Quarto
- Cylinder
- Cuboid

**Testing:**
The "static getShape()" method has been implemented for each shape. Testing involves a comprehensive assessment of all shapes, including their respective getters, setters, and member variables.

## Testing Framework

Throughout these testing procedures, the Google Test framework has been employed to ensure the robustness of the implemented functionalities.

Feel free to explore the testing methods, and don't hesitate to reach out if you have any questions or need further clarification. Happy testing!
