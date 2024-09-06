## How to run files:

1. Compile and create an executible for `*gc.c` file:

```
gcc -Wall incrementalgc.c -o incrementalgc -llua -lm -ldl
```

> Ensure that lua source files' path is mentioned in global PATH variable 
2. Use valgrind to generate a `.out` file for each executable file

```
valgrind --tool=callgrind ./incrementalgc
```

3. Use [gprof2dot](https://github.com/jrfonseca/gprof2dot) to generate a `.dot` file to be used to generate call graphs

```
gprof2dot --format=callgrind --output=out.dot ./callgrind.out.<some number>
```

4. Finally, generate the call graph

```
dot -Tpng out.dot -o gc.png
```

## Instructions to perform perf analysis:

Install [perf](https://perf.wiki.kernel.org/index.php/Main_Page) and run following code on the executible file generated in step 1:

```
perf stat -B -e branch-misses,page-faults,cache-misses,instructions,cycles ./fullgc
```
There is a chance you get performace monitoring access limit. Run the following code to increase the limit:

``` 
sudo sysctl kernel.perf_event_paranoid=-1
```

### Performing No GC Analysis:
Simply, use `lua_gc(L, LUA_GCSTOP, 0)` to stop the garbage collector but don't collect it i.e. no need to use `lua_gc(L, LUA_GCCOLLECT, 0)`

### Analysing call graphs:
Refer [gprof2dot](https://github.com/jrfonseca/gprof2dot) to understand what call graph structure looks like.   

### Naming convention used in call graph pictures:   
Each graph ends with a numeral from 0 to 3. 
- `*_0.png`: n = 100 ,m = 1000
- `*_1.png`: n = 100, m = 100
- `*_2.png`: n = 100, m = 500
- `*_3.png`: n = 100, m = 5000

