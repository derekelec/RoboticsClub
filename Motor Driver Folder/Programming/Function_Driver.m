%%#codegen
% INPUTS
% This is the section that defines what are inputs and what are outputs
% this is to be left static for now as to allow for debugging. This is
% where you would assign sensors to certain pins
% nFault = 0; % pin ___

% Outputs
% This is the section that defines what pins are used as outputs and such.
% This section will contain dummy variables for now

% AIN1 = 0; % pin ___
% AIN2 = 0; % pin ___
% BIN1 = 0; % pin ___
% BIN2 = 0; % pin ___
% nSleep = 0; % pin ___

% Functions
% test built a Motor Driver Board Object
MDB = MotorDriverBoard;
MDB = MDB.FullForward(3);
