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
| 2^20  | 0.217029s  | 0.048229s | Assembly was faster by 0.1688s |
| 2^24  | 2.071286s  | 0.324686s | Assembly was faster by 1.7466s |
| 2^27  | 9.961686s  | 1.270257s | Assembly was faster by 8.691429s |

# Observation
Lorem ipsum

# Project Screenshots
The following figures demonstrate a successful run of the project in both debug mode and release mode. The respective vector sizes used are displayed together with a side-by-side comparison of the results after programming the given task in both the C and x86-64 assembly languages. 

## Debug Mode

## Release Mode

# Developers
(S17) Mary Erika Culala & Gleezell Vina Uy

