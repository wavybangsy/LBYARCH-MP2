# LBYARCH Machine Project 2
This program implements a kernel in C program and x86-64 assembly language that performs a 1-D stencil of vector X and places the result in vector Y.

# Comparative Analysis
## Release Mode
| Vector Size  | C runtime | x86-64 Assembly runtime | Remarks
| ------------- | ------------- | ------------- | ------------- |
| 2^20  | 0.059971s  | 0.020886s | Assembly was faster by 0.039085s |
| 2^24  | 1.099657s  | 0.176171s | Assembly was faster by 0.923486s |
| 2^27  | 8.088571s  | 1.204257s | Assembly was faster by 6.884314s |

## Debug Mode
| Vector Size  | C runtime | x86-64 Assembly runtime | Remarks
| ------------- | ------------- | ------------- | ------------- |
| 2^20  | 0.068114s  | 0.018029s | Assembly was faster by 0.050085s |
| 2^24  | 0.839886s  | 0.154057s | Assembly was faster by 0.685829s |
| 2^27  | 6.911629s  | 1.085429s | Assembly was faster by 5.8262s |

# Observation
With the given project implementation, a side-by-side comparison of the two kernels with the same task showed that the x86-64 assembly runtime performed faster at all times. The table figures shown also demonstrate how the runtime of the Assembly language had a larger gap when compared to the task implemented in the C language. 

The same inputs and outputs were also crosschecked to ensure the capability of both languages to implement the given task, namely performing a 1-D stencil of the vector X and placing the results in vector Y. 

Moreover, the recorded runtime of the release mode table, as shown in the table figure above, indicates a faster rate of runtime. This is caused by the optimization capabilities of the code after testing the program in Release mode vs Debug mode.
# Project Screenshots
The following figures demonstrate a successful run of the project in both debug mode and release mode. The respective vector sizes used are displayed together with a side-by-side comparison of the results after programming the given task in both the C and x86-64 assembly languages. 

## Debug Mode

![image](https://github.com/wavybangsy/LBYARCH-MP2/assets/26676907/42f49348-341d-418a-8b2a-48a3cd997640)

## Release Mode
![release2](https://github.com/wavybangsy/LBYARCH-MP2/assets/76273496/b238fed9-51c4-4829-a133-1a3d43c156aa)

# Developers
(S17) Mary Erika Culala & Gleezell Vina Uy

