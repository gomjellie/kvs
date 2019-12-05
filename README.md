# kvs

## build

### static library

build

```sh
make static
```

run

```sh
./test_static put.txt get.txt result_static.txt
```

### dynamic library

build

```sh
make dll

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
```

run

```sh
./test_dll put.txt get.txt result_dll.txt
```

