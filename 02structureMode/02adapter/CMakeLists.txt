project(adapter)

aux_source_directory(. DIR_SRCS)

#创建执行程序
add_executable(${PROJECT_NAME} ${DIR_SRCS})