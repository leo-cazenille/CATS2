set(srcs
    routines/TrackingRoutine.cpp
    routines/BlobDetector.cpp
    settings/TrackingSettings.cpp
    settings/TrackingRoutineSettings.cpp
    settings/BlobDetectorSettings.cpp
    TrackingData.cpp
    TrackingSetup.cpp
)

set(hdrs
    TrackingFactory.hpp
    routines/TrackingRoutineType.hpp
)

qt5_add_resources(resources icons.qrc)
qt5_wrap_ui(uis_hdrs gui/TrackingRoutineWidget.ui)

include_directories(${CMAKE_SOURCE_DIR}/source/common)
include_directories(${CMAKE_SOURCE_DIR}/source/video-grabber)
add_library(tracker SHARED ${srcs} ${hdrs} ${uis_hdrs} ${resources})
target_link_libraries(tracker video-grabber common
                      Qt5::Core Qt5::Widgets
                      ${OpenCV_LIBS} ${LIBTSAI_LIBRARY})

