# Distributed under the OSI-approved MIT License.  See accompanying
# file LICENSE or https://github.com/Crascit/DownloadProject for details.

cmake_minimum_required(VERSION 2.8.2)

project(libigl-download NONE)

include(ExternalProject)
ExternalProject_Add(libigl-download
                    GIT_REPOSITORY;https://github.com/libigl/libigl.git;GIT_TAG;e699d257fe860d4fd82709835e72438bd0cd1533
                    SOURCE_DIR          "/Users/gongliheng/Documents/gp/assignments/project/GM_Final_Project/external/libigl"
                    BINARY_DIR          "/Users/gongliheng/Documents/gp/assignments/project/GM_Final_Project/build/libigl-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
)
