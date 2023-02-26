##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Race1
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks"
ProjectPath            := "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/Race1"
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
CmpOptions             := -g -DDEBUG $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=$(LibrarySwitch)pthread 
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/race$(ObjectSuffix) 

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
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/Race1/main.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/Race1/main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/Race1/main.c"

$(IntermediateDirectory)/race$(ObjectSuffix): race.c $(IntermediateDirectory)/race$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/Race1/race.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/race$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/race$(DependSuffix): race.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/race$(ObjectSuffix) -MF$(IntermediateDirectory)/race$(DependSuffix) -MM "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/Race1/race.c"

$(IntermediateDirectory)/race$(PreprocessSuffix): race.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/race$(PreprocessSuffix) "/home/alex/Work2018/OS/Lessons/Lesson9/Tasks/Lesson9Tasks/Race1/race.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/race$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/race$(DependSuffix)
	$(RM) $(IntermediateDirectory)/race$(PreprocessSuffix)
	$(RM) $(OutputFile)


