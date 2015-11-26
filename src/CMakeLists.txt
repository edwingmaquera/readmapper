add_executable(readmapper readmapper.cpp sequence.cpp fastareader.cpp)
add_executable(seqreader seqreader.cpp 
                         sequence.cpp 
                         fastareader.cpp
                         fastqreader.cpp)

add_executable(seqalign seqalign.cpp 
                        alignment.cpp
                        sequence.cpp 
                        fastareader.cpp
                        fastqreader.cpp
                        sw.cpp)

add_executable(aligntest aligntest.cpp 
                         alignment.cpp
                         sequence.cpp)

install (TARGETS readmapper seqreader seqalign aligntest DESTINATION bin)