#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Data.o \
	${OBJECTDIR}/src/data_constants.o \
	${OBJECTDIR}/src/data_types.o \
	${OBJECTDIR}/src/server.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thread_lock_mutex

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thread_lock_mutex: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thread_lock_mutex ${OBJECTFILES} ${LDLIBSOPTIONS} -lthrift -lthriftnb -levent -lkyotocabinet -lz -lstdc++ -lrt -lpthread -lm -lc -lPocoUtil -lPocoXML -lPocoJSON -lPocoNet -lPocoFoundation

${OBJECTDIR}/src/Data.o: src/Data.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I/usr/local/include/boost -I/usr/local/include/Poco -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Data.o src/Data.cpp

${OBJECTDIR}/src/data_constants.o: src/data_constants.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I/usr/local/include/boost -I/usr/local/include/Poco -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/data_constants.o src/data_constants.cpp

${OBJECTDIR}/src/data_types.o: src/data_types.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I/usr/local/include/boost -I/usr/local/include/Poco -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/data_types.o src/data_types.cpp

${OBJECTDIR}/src/server.o: src/server.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/thrift -I/usr/local/include/boost -I/usr/local/include/Poco -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/server.o src/server.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thread_lock_mutex

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
