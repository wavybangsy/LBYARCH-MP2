# LBYARCH Machine Project 2
This program implements a kernel in C program and x86-64 assembly language that performs a 1-D stencil of vector X and places the result in vector Y.

# Comparative Analysis
## Release Mode
| Vector Size  | C runtime | x86-64 Assembly runtime | Remarks
| ------------- | ------------- | ------------- | ------------- |
| 2^20  | 0.162800s  | 0.045257s | Assembly was faster by 0.117543s |
| 2^24  | 2.650286s  | 0.234514s | Assembly was faster by 2.415772s |
| 2^27  | 13.868200s  | 3.083600s | Assembly was faster by 10.7846s |

## Debug Mode
| Vector Size  | C runtime | x86-64 Assembly runtime | Remarks
| ------------- | ------------- | ------------- | ------------- |
| 2^20  | 0.068114s  | 0.018029s | Assembly was faster by 0.1688s |
| 2^24  | 0.839886s  | 0.154057s | Assembly was faster by 1.7466s |
| 2^27  | 6.911629s  | 1.085429s | Assembly was faster by 8.691429s |

# Observation
Lorem ipsum

# Project Screenshots
The following figures demonstrate a successful run of the project in both debug mode and release mode. The respective vector sizes used are displayed together with a side-by-side comparison of the results after programming the given task in both the C and x86-64 assembly languages. 

## Debug Mode

<img width="1097" alt="debug2" src="https://github.com/wavybangsy/LBYARCH-MP2/assets/76273496/8982d8d0-7fd9-4389-9166-e343356a5dd7">

## Release Mode
![Release_Screenshot](https://github.com/wavybangsy/LBYARCH-MP2/assets/26676907/209987c7-7ddc-45c2-b6ee-0b34f3525391)

# Developers
(S17) Mary Erika Culala & Gleezell Vina Uy

