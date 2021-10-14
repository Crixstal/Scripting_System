# **Research**

## **Summary**

- [SWIG](##SWIG)
- [Pybind11](##Pybind11)

<br>

For this project we had to choose between SWIG and pybind11 to manage the C++/Python interface.
Here is a brief summary of what made us choose pybind11.

<br>

## **SWIG**

The documentation is not very detailed, it's complicated to install and to use.

<br>

## **Pybind11**

We used this list of very complete videos on how to install and use pybind11:
https://www.youtube.com/playlist?list=PLb9uFnQyeGTcKIHNUNUUuLbRhumAZd-fy

We found pybind11 to be quite easy to use once we understood the role of each project (app and module) in the solution and how they work together.  
Its use also allowed us to better understand the functioning of CMake, which allowed us to better set up the solution.

In conclusion, pybind11 is a very good tool to interface C++/Python.  
However, we might have needed a little more time to better architect our project now that pybind11 allows us to use python and the hot reload.