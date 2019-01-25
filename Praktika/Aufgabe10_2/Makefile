CXX = cl
CXXFLAGS = /EHsc /nologo
MAIN_EXECUTABLE = main.exe

LD = link
LDFLAGS = /nologo

$(MAIN_EXECUTABLE): main.obj sort.obj
	$(LD) $(LDFLAGS) $^ /OUT:$@
	
clean:
	del *.obj
	
distclean: clean
	del $(MAIN_EXECUTABLE)
	
all: $(MAIN_EXECUTABLE)
	
main.obj: main.cpp
	$(CXX) $(CXXFLAGS) /c $<
	
%.obj: %.cpp %.h
	$(CXX) $(CXXFLAGS) /c $<

	
.PHONY: clean
.PHONY: distclean
.PHONY: all