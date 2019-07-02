#citation: https://oregonstate.instructure.com/courses/1719543/pages/lecture-makefiles?module_item_id=18712398

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGs += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -w

LDFLAGS = 

SOURCES = main.cpp Queue.cpp Helper.cpp Vampire.cpp Die.cpp Game.cpp Character.cpp Barbarian.cpp Blue_Men.cpp Medusa.cpp Harry_Potter.cpp 

HEADERS = Queue.hpp Helper.hpp Vampire.hpp Character.hpp Die.hpp Game.hpp Barbarian.hpp Blue_Men.hpp Medusa.hpp Harry_Potter.hpp

OBJS = main.o 
DOCUMENTS = *.pdf 

FANTASY COMBAT: ${SOURCES} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${SOURCES} -o FANTASY_COMBAT 

${OBJS}: ${SOURCES}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm FANTASY_COMBAT 
	rm -R FANTASY_COMBAT.dSYM
zip:
	zip Project4_Chris_Nelson.zip ${SOURCES} ${HEADERS} ${DOCUMENTS} makefile

unzip:
	unzip Project4_Chris_Nelson.zip 
