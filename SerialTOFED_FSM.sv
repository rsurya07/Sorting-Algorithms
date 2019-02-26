/*******************************************************
SerialTOFED_FSM.sv - module that determine if a bitstream is 3 out of 5 word

Name: Surya Ravikumar
Date: 2/10/2019

Description:   THis module reads in a bitstream, and determines if the bitstream is a 
			   3 out of 5 word. The module uses a state machine to keep track of the bits.
			   Each bit of the bitstream is received every clock
**************************************************************************/




package states;
	typedef enum {B0_0, B1_0, B1_1, B2_0, B2_1, B2_2, B3_0, B3_1, B3_2, B3_3, B4_0, B4_1, B4_2, B4_3, B4_4, B5_0, B5_1, B5_2, B5_3, B5_4, B5_5} states_t;
endpackage

import SerialTOFEDDefs::*;

module SerialTOFED_FSM(
    input clk,       // Clock 
    input resetH,    // Asynchronous reset active High
    input din,      // Data in
    output bool_t valid// Valid out
);    

    import states::*;		//import package
	
    states_t current_state;	//state variables
    states_t next_state;

    always_ff @(negedge clk or posedge resetH) //on negative edge of clock or on reset
    begin
	if(!resetH)
	begin
	    unique case (current_state)		//get next state based on current state and input
	        B0_0: next_state <= din ? B1_1 : B1_0;	//one bit received and din == 1 or 0
			B1_0: next_state <= din ? B2_1 : B2_0;	//2 bits recived and din 1 or 0
			B1_1: next_state <= din ? B2_2 : B2_1;	//so on...
			B2_0: next_state <= din ? B3_1 : B3_0;
			B2_1: next_state <= din ? B3_2 : B3_1;
			B2_2: next_state <= din ? B3_3 : B3_2;
			B3_0: next_state <= din ? B4_1 : B4_0;
			B3_1: next_state <= din ? B4_2 : B4_1;
			B3_2: next_state <= din ? B4_3 : B4_2;
			B3_3: next_state <= din ? B4_4 : B4_3;
			B4_0: next_state <= din ? B5_1 : B5_0;
			B4_1: next_state <= din ? B5_2 : B5_1;
			B4_2: next_state <= din ? B5_3 : B5_2;
			B4_3: next_state <= din ? B5_4 : B5_3;
			B4_4: next_state <= din ? B5_5 : B5_4;
			B5_0: next_state <= din ? B1_1 : B1_0;
			B5_1: next_state <= din ? B1_1 : B1_0;
			B5_2: next_state <= din ? B1_1 : B1_0;
			B5_3: next_state <= din ? B1_1 : B1_0;
			B5_4: next_state <= din ? B1_1 : B1_0;
			B5_5: next_state <= din ? B1_1 : B1_0;
	    endcase
	end

	else
	begin
	    next_state <= B0_0;		//on reset, reset state
	end
    end

    always_comb
    begin
	if(!resetH)			//if not reset
	begin
	    current_state = next_state;	//update state
	    
	    if(current_state == B5_3)	//if valid state reached
		valid = TRUE;

	    else
		valid = FALSE;
	end

	else
	begin
	    current_state = B0_0;		//on reset, reset state
	    valid = FALSE;	//invalidate valid signal
	end
    end

 endmodule:SerialTOFED_FSM
    
