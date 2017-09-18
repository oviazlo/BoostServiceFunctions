ADD_EXECUTABLE ( libTesting libTesting.cxx )

TARGET_LINK_LIBRARIES (libTesting ${ROOT_LIBRARIES} ${Boost_LIBRARIES} BoostServiceFunctions)
