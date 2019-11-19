#######################################################
 # @Author: B159973
 # @Date:   19/11/2019
 # @Course: Programming Skills - 2019
 # @University of Edinburgh
#######################################################

#########################Libraries#####################
import re
import string
import subprocess
import os
import sys
#######################################################

class Reg_Lib:
#--------------------------- CONSTANTS OF REGRESSION LIBRARY ---------------------------------#
	_DAT_FILE = ".dat"
	_PGM_FILE = ".pgm"
	
	#--Make commands--#	
	_make_build  = "make -C "
	_make_clean = "make clean -C "
	
	#--Essential Filenames--#
	_move_script = "move.sh"
	_stdout_file = "stdout"
	_pgm_file = "map.pgm"
	_dat_file = "map.dat"	
	_exe_v1 = "percolate"
	_exe_v2 = "run.sh"
	
	#--Essential Directories--#
	_test_dir = "test"
	_output_dir = "output"
	_bin_dir = "bin"

	#--10 Instances per Version--#
	_versions_1 = ["v1_instance_1","v1_instance_2","v1_instance_3","v1_instance_4","v1_instance_5","v1_instance_6","v1_instance_7","v1_instance_8","v1_instance_9","v1_instance_10"]
	_versions_2 = ["v2_instance_1","v2_instance_2","v2_instance_3","v2_instance_4","v2_instance_5","v2_instance_6","v2_instance_7","v2_instance_8","v2_instance_9","v2_instance_10"]

#--------------------------- CONSTRUCTOR---------------------------------#
	"""
	Class Reg_Lib: (Regression Library) 
	1. Simple Library Implementation
	2. Compile, run and clean instances for a proper regression test. 
	3. Accumulation of output of each instance.  
	"""
 	def __init__(self):
 		pass
#----------------------------------------------------------------------------------------------#
#---------------------------VERSION 1 RUN & COMPILE TEST CASES ---------------------------------#
	"""
	Run the executables for each instance
	"""
	def run_v1(self):
		for v in Reg_Lib._versions_1:
			cmd_ch =  "cd " + Reg_Lib._test_dir+"/" + v + " ; "
			cmd_ex = "./" + Reg_Lib._exe_v1
			cmd = cmd_ch+cmd_ex
			#Open a up a process and run the executable
			proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)  
			# Execute ./percolate
			shell_out,shell_err = proc.communicate(cmd)   
			self.print_cmd(cmd,shell_out,shell_err)
			# Execute move script 
			self.exe_perm(cmd_ch ,Reg_Lib._move_script)
			self.exe_script(cmd_ch ,Reg_Lib._move_script)
			# Write the stdout into the output file
			self.write_file(Reg_Lib._test_dir+"/"+v+"/"+Reg_Lib._output_dir+"/"+Reg_Lib._stdout_file,shell_out)
	"""
	Compile source files for each instance
	"""
	def compile_v1(self):
		for v in Reg_Lib._versions_1:
			cmd = Reg_Lib._make_build + Reg_Lib._test_dir +"/"+ v
			proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)	
			#Execute Command
			shell_out,shell_err = proc.communicate(cmd)   
			self.print_cmd(cmd,shell_out,shell_err)

	"""
	Clean up executables and output files 
	"""
	def clean_v1(self):
		for v in Reg_Lib._versions_1:
			cmd = Reg_Lib._make_clean + Reg_Lib._test_dir +"/"+ v
			proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)
			#Execute Command
			shell_out,shell_err = proc.communicate(cmd)
			self.print_cmd(cmd,shell_out,shell_err)
#----------------------------------------------------------------------------------------------#

#---------------------------VERSION 2 RUN & COMPILE TEST CASES---------------------------------#
	"""
	Run the executables for each instance
	"""
	def run_v2(self):
		for v in Reg_Lib._versions_2:
			cmd_ch =  "cd " + Reg_Lib._test_dir+"/" + v +"/"+ Reg_Lib._bin_dir + " ; "
			cmd_ex = "./" + Reg_Lib._exe_v2
			# Allow bin/run.sh script execution and run
			self.exe_perm(cmd_ch,cmd_ex)
			cmd = cmd_ch+cmd_ex
			proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)  
			# Execute ./percolate
			shell_out,shell_err = proc.communicate(cmd)   
			self.print_cmd(cmd,shell_out,shell_err)
			# Allow move.sh script execution
			cmd_ch =  "cd " + Reg_Lib._test_dir+"/" + v + " ; "
			self.exe_perm(cmd_ch ,Reg_Lib._move_script)
			# Execute move script
			self.exe_script(cmd_ch ,Reg_Lib._move_script)
			# Write the stdout into the output file
			self.write_file(Reg_Lib._test_dir+"/"+v+"/"+Reg_Lib._output_dir+"/"+Reg_Lib._stdout_file,shell_out)
	
	#Compile version 2 code		
	def compile_v2(self):
		for v in Reg_Lib._versions_2:
			cmd = Reg_Lib._make_build + Reg_Lib._test_dir +"/"+ v
			proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)
			#Execute Command
			shell_out,shell_err = proc.communicate(cmd)   
			self.print_cmd(cmd,shell_out,shell_err)

	"""
	Clean up executables and output files 
	"""
	def clean_v2(self):
		for v in Reg_Lib._versions_2:
			cmd = Reg_Lib._make_clean + Reg_Lib._test_dir +"/"+ v
			proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)

			#Execute Command
			shell_out,shell_err = proc.communicate(cmd)
			self.print_cmd(cmd,shell_out,shell_err)		
	
	#----------------------------------------------------------------------------------------------#	
	#---------------------------------HELPER FUNCTIONS---------------------------------------------#
	"""
	Append into a file the output.
	@param file: The file to append the data
	@param output: Data to be appended to the file 			
	"""	
	def write_file(self, file, output):
		file = open(file, "w")
		file.write(output)
		file.close()
	
	"""
	Give executable permission to the script 
	@param  script: Script to give the permission
	@param	path:	Path of the script file 
	"""
	def exe_perm(self,path,script):
		cmd = path+" chmod +x " + script
		proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)
		shell_out,shell_err = proc.communicate(cmd)
		self.print_cmd(cmd,shell_out,shell_err)
	
	"""
	Execute a script 
	@param  script: Script to execute
	@param	path:	Path of the script file 
	"""
	def exe_script(self,path,script):
		cmd = path+"./"+script
		proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True)
		shell_out,shell_err = proc.communicate(cmd)
		self.print_cmd(cmd,shell_out,shell_err)
	
	"""
	Gather the output from the specific file and modify it to only numbers
	@param  file: The filename with path for extracting the output
	"""
	def get_output(self,file):
		out = open(file,"r")
		data = out.read()
		data = re.sub('[^0-9]', '', data)
		return data

	"""
	Print the nessesary outputs and errors of each finished command 
	@param  cmd: Executed command
	@param shell_out: The output (stdout) of the executed command.
	@param shell_err: The error log of the executed command. 
	"""
	def print_cmd(self,cmd,shell_out,shell_err):
		print("========================================================\n")
		print('\nOUTPUT of command: ' + str(cmd)+"\n" + shell_out.decode('ascii'))
		print('\nERRORS of command: '+ str(cmd)  +"\n"+ shell_err.decode('ascii'))
