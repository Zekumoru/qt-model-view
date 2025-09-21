cmake_minimum_required(VERSION 3.16)

project(ModelView VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appModelView
    main.cpp
)

set(qml_files
    Main.qml
    components/CppListView.qml
    components/IntegerListView.qml
    utils/model.js
)

set(cpp_sources
    entities/TodoList.h
    entities/TodoList.cpp
    models/TodoModel.h
    models/TodoModel.cpp
)

qt_add_qml_module(appModelView
    URI ModelView
    VERSION 1.0
    QML_FILES ${qml_files}
    SOURCES ${cpp_sources}
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appModelView PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appModelView
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# [TTRL] 8. Make sure that models are discoverable
# The docs state:
# "Furthermore, your class declarations have to live in
#  headers reachable via your project's include path."
# (See: https://doc.qt.io/qt-6/qtqml-cppintegration-definetypes.html#preconditions)
target_include_directories(appModelView
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/models
        # [TTRL-2] 13. Make sure that the entities are discoverable
        ${CMAKE_CURRENT_SOURCE_DIR}/entities
)

target_link_libraries(appModelView
    PRIVATE Qt6::Quick
)
target_link_libraries(appModelView PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appModelView
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
