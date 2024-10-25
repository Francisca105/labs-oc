# Computer Organization (OC) Lab Assignments

This repository contains the solutions for the Computer Organization course lab assignments at Instituto Superior Técnico (IST).

## Repository Structure

The solutions are organized in different branches from main:

* [main ](https://github.com/Francisca105/labs-oc/tree/main)- Contains base documentation and lab assignment descriptions
* [lab-1 ](https://github.com/Francisca105/labs-oc/tree/lab-1)- Pipeline analysis using WinMIPS64 simulator
* [lab-2 ](https://github.com/Francisca105/labs-oc/tree/lab-2)- Cache modeling and performance analysis using PAPI
* [lab-3 ](https://github.com/Francisca105/labs-oc/tree/lab-3)- Cache system implementation and memory hierarchy simulation

## Lab 1: Cache System Implementation

Implementation of a configurable cache hierarchy simulator in C. The project includes:

* Single-level direct-mapped L1 cache
* Two-level cache with direct-mapped L2
* Two-level cache with 2-way set associative L2

### Project Structure

* `Cache.h` - Configuration constants and parameters
* `SimpleCache.h` - Base interface definitions
* `L1Cache.{c,h}` - L1 cache implementation
* `L2Cache.{c,h}` - L2 cache implementation
* `L2W.{c,h}` - Set associative L2 cache implementation

## Lab 2: Cache Modeling and Performance Analysis

Analysis and optimization of cache performance using PAPI tools. The lab includes:

* L1 and L2 cache modeling
* Cache characteristics determination
* Matrix multiplication optimization techniques
* Performance profiling using PAPI counters

### Tools Required

* PAPI library
* GCC compiler
* Linux environment

## Lab 3: Pipeline Analysis

Analysis of pipelined computer architecture using WinMIPS64 simulator (v1.57). The lab focuses on:

* Understanding pipeline stages and hazards
* Data forwarding techniques
* Branch prediction analysis
* Code optimization techniques (loop unrolling, branch delay slots)
* Performance analysis and optimization

### Tools Required

* WinMIPS64 simulator v1.57
* Linux environment (can use Wine for WinMIPS64)

### Build Requirements

* GCC compiler
* Make build system
* Linux environment (x86-64)

## Guides

Detailed guides for each lab assignment can be found in:

* [lab1.pdf](https://github.com/Francisca105/labs-oc/blob/lab-1/oc-lab1-guide.pdf) - Pipeline analysis assignment
* [lab2.pdf ](https://github.com/Francisca105/labs-oc/blob/lab-2/oc-lab2-guide.pdf)- Cache modeling and performance analysis
* [lab3.pdf](https://github.com/Francisca105/labs-oc/blob/lab-3/oc-lab3.pdf) - Cache implementation assignment

## Authors

* Patrícia Gameiro
* José Frazão
* Francisca Almeida
