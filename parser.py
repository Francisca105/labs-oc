import os

def parse_counters(output):
    lines = output.splitlines()
    dcm_after = ld_after = sr_after = clock_cycles = clock_time = 0.0

    for line in lines:
        if "PAPI_L1_DCM" in line and "After stopping" in line:
            dcm_after = float(line.split(":")[1].strip())
        elif "PAPI_LD_INS" in line and "After stopping" in line:
            ld_after = float(line.split(":")[1].strip())
        elif "PAPI_SR_INS" in line and "After stopping" in line:
            sr_after = float(line.split(":")[1].strip())
        elif "Wall clock cycles" in line:
            clock_cycles = float(line.split(":")[1].strip())
        elif "Wall clock time" in line:
            clock_time = float(line.split(":")[1].strip())
    
    ld_sr_after = ld_after + sr_after

    return dcm_after, ld_sr_after, clock_cycles, clock_time

def write_tsv(data, filename):
    header = "DCM\tLD+SR\tClock_Cycles\tClock_Time\n"
    with open(filename, 'w') as file:
        file.write(header)
        file.write(f"{data[0]}\t{data[1]}\t{data[2]}\t{data[3]}\n")

def process_files(input_folder):
    for i in range(10):
        input_filename = f"mm1_{i}.txt"
        output_filename = f"mm1_{i}.tsv"
        
        input_filepath = os.path.join(input_folder, input_filename)
        
        if os.path.exists(input_filepath):
            with open(input_filepath, 'r') as file:
                content = file.read()
            
            parsed_data = parse_counters(content)
            
            write_tsv(parsed_data, os.path.join(input_folder, output_filename))
            print(f"Processed {input_filename} -> {output_filename}")
        else:
            print(f"File {input_filename} does not exist")

input_folder = './data/mm_1'
process_files(input_folder)
