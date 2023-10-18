

foreach(EXAMPLE read)
  add_executable(${EXAMPLE}
    ${EXAMPLE}.cpp
  )

  target_link_libraries(${EXAMPLE}
    ztalk
  )
endforeach()
