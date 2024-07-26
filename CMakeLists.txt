cmake_minimum_required(VERSION 3.10)

project(csh)

add_executable(csh
    src/builtin/csh_builtin.c
    src/builtin/csh_cd.c
    src/builtin/csh_exit.c
    src/builtin/csh_launch.c
    src/util/csh_check_and_reallock.c
    src/util/csh_read_line.c
    src/util/csh_split_line.c
    src/csh.c
    src/main.c
)
