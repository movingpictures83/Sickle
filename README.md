# Sickle
# Language: C++
# Input: TXT
# Output: FASTQ
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: Sickle

PluMA plugin to trim adapters using Sickle (Joshi and Fass, 2011)

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
fastq: Input file of sequences
quality: Minimum quality
type: Type of data (sanger, illumina, etc.)

Trimmed sequences are sent to the output FASTQ.
