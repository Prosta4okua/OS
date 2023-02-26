##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Intergal
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test"
ProjectPath            := "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alexander
Date                   :=28.10.2017
CodeLitePath           :="/home/alex/.codelite"
LinkerName             :=gcc
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=gcc
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)pthread 
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/integr$(ObjectSuffix) $(IntermediateDirectory)/my_threads$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.c $(IntermediateDirectory)/main$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/main.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/main.c"

$(IntermediateDirectory)/integr$(ObjectSuffix): integr.c $(IntermediateDirectory)/integr$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/integr.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/integr$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/integr$(DependSuffix): integr.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/integr$(ObjectSuffix) -MF$(IntermediateDirectory)/integr$(DependSuffix) -MM "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/integr.c"

$(IntermediateDirectory)/integr$(PreprocessSuffix): integr.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/integr$(PreprocessSuffix) "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/integr.c"

$(IntermediateDirectory)/my_threads$(ObjectSuffix): my_threads.c $(IntermediateDirectory)/my_threads$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/my_threads.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/my_threads$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/my_threads$(DependSuffix): my_threads.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/my_threads$(ObjectSuffix) -MF$(IntermediateDirectory)/my_threads$(DependSuffix) -MM "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/my_threads.c"

$(IntermediateDirectory)/my_threads$(PreprocessSuffix): my_threads.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/my_threads$(PreprocessSuffix) "/home/alex/Work2017/OS/Lessons/Lesson8/New2017/Lesson8Test/Intergal/my_threads.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/integr$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/integr$(DependSuffix)
	$(RM) $(IntermediateDirectory)/integr$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/my_threads$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/my_threads$(DependSuffix)
	$(RM) $(IntermediateDirectory)/my_threads$(PreprocessSuffix)
	$(RM) $(OutputFile)


