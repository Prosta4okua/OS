##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=RWTest
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks"
ProjectPath            := "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alexander
Date                   :=31.10.2018
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
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/tarray$(ObjectSuffix) $(IntermediateDirectory)/task$(ObjectSuffix) $(IntermediateDirectory)/treads$(ObjectSuffix) 

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
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/main.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/main.c"

$(IntermediateDirectory)/tarray$(ObjectSuffix): tarray.c $(IntermediateDirectory)/tarray$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/tarray.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/tarray$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tarray$(DependSuffix): tarray.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/tarray$(ObjectSuffix) -MF$(IntermediateDirectory)/tarray$(DependSuffix) -MM "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/tarray.c"

$(IntermediateDirectory)/tarray$(PreprocessSuffix): tarray.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tarray$(PreprocessSuffix) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/tarray.c"

$(IntermediateDirectory)/task$(ObjectSuffix): task.c $(IntermediateDirectory)/task$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/task.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/task$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/task$(DependSuffix): task.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/task$(ObjectSuffix) -MF$(IntermediateDirectory)/task$(DependSuffix) -MM "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/task.c"

$(IntermediateDirectory)/task$(PreprocessSuffix): task.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/task$(PreprocessSuffix) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/task.c"

$(IntermediateDirectory)/treads$(ObjectSuffix): treads.c $(IntermediateDirectory)/treads$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/treads.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/treads$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/treads$(DependSuffix): treads.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/treads$(ObjectSuffix) -MF$(IntermediateDirectory)/treads$(DependSuffix) -MM "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/treads.c"

$(IntermediateDirectory)/treads$(PreprocessSuffix): treads.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/treads$(PreprocessSuffix) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/RWTest/treads.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tarray$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tarray$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tarray$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/task$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/task$(DependSuffix)
	$(RM) $(IntermediateDirectory)/task$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/treads$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/treads$(DependSuffix)
	$(RM) $(IntermediateDirectory)/treads$(PreprocessSuffix)
	$(RM) $(OutputFile)


