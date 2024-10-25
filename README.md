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

## Building and Running

### Lab 2

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">bash</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]"><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed"><code class="language-bash"><span><span class="token"># Build PAPI</span><span>
</span></span><span><span></span><span class="token">cd</span><span> papi-X.X.X/src
</span></span><span>./configure
</span><span><span></span><span class="token">make</span><span>
</span></span><span>
</span><span><span></span><span class="token"># Run cache modeling programs</span><span>
</span></span><span><span></span><span class="token">cd</span><span> cm1/
</span></span><span><span></span><span class="token">make</span><span>
</span></span><span>./cm1
</span><span>
</span><span><span></span><span class="token"># Run matrix multiplication tests</span><span>
</span></span><span><span></span><span class="token">cd</span><span> mm1/
</span></span><span><span></span><span class="token">make</span><span>
</span></span><span>./mm1</span></code></div></div></div></pre>

### Lab 1

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">bash</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]"><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed"><code class="language-bash"><span><span class="token"># Build all cache implementations</span><span>
</span></span><span><span></span><span class="token">make</span><span> all
</span></span><span>
</span><span><span></span><span class="token"># Run tests</span><span>
</span></span><span>./test_l1cache
</span><span>./test_l2cache
</span><span>./test_l2cache_assoc</span></code></div></div></div></pre>

### Lab 3

<pre><div class="relative flex flex-col rounded-lg"><div class="text-text-300 absolute pl-3 pt-2.5 text-xs">bash</div><div class="pointer-events-none sticky my-0.5 ml-0.5 flex items-center justify-end px-1.5 py-1 mix-blend-luminosity top-0"><div class="from-bg-300/90 to-bg-300/70 pointer-events-auto rounded-md bg-gradient-to-b p-0.5 backdrop-blur-md"><button class="flex flex-row items-center gap-1 rounded-md p-1 py-0.5 text-xs transition-opacity delay-100 hover:bg-bg-200 opacity-60 hover:opacity-100"><svg xmlns="http://www.w3.org/2000/svg" width="14" height="14" fill="currentColor" viewBox="0 0 256 256" class="text-text-500 mr-px -translate-y-[0.5px]"><path d="M200,32H163.74a47.92,47.92,0,0,0-71.48,0H56A16,16,0,0,0,40,48V216a16,16,0,0,0,16,16H200a16,16,0,0,0,16-16V48A16,16,0,0,0,200,32Zm-72,0a32,32,0,0,1,32,32H96A32,32,0,0,1,128,32Zm72,184H56V48H82.75A47.93,47.93,0,0,0,80,64v8a8,8,0,0,0,8,8h80a8,8,0,0,0,8-8V64a47.93,47.93,0,0,0-2.75-16H200Z"></path></svg><span class="text-text-200 pr-0.5">Copy</span></button></div></div><div><div class="code-block__code !my-0 !rounded-lg !text-sm !leading-relaxed"><code class="language-bash"><span><span class="token"># Run WinMIPS64 simulator</span><span>
</span></span><span>wine winmips64.exe
</span><span>
</span><span><span></span><span class="token"># Load program file</span><span>
</span></span><span><span>File -</span><span class="token">></span><span> Open -</span><span class="token">></span><span> prog.s</span></span></code></div></div></div></pre>

## Development Guidelines

1. Develop labs in sequence
2. Test each component thoroughly before moving to next
3. Follow provided interfaces in header files
4. Maintain configurability via Cache.h
5. Use write-back policy and LRU replacement where applicable

## Guides

Detailed guides for each lab assignment can be found in:

* [lab1.pdf](https://github.com/Francisca105/labs-oc/blob/lab-1/oc-lab1-guide.pdf) - Pipeline analysis assignment
* [lab2.pdf ](https://github.com/Francisca105/labs-oc/blob/lab-2/oc-lab2-guide.pdf)- Cache modeling and performance analysis
* [lab3.pdf](https://github.com/Francisca105/labs-oc/blob/lab-3/oc-lab3.pdf) - Cache implementation assignment

## Authors

* Patrícia Gameiro
* José Frazão
* Francisca Almeida
