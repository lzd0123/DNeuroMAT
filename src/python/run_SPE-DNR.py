import SPE_DNR
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--image_path", "-i", type=str, default="None", help="image path")
    parser.add_argument("--output_path", "-o", type=str, default="None", help="output path")
    args = parser.parse_args()
    runner = SPE_DNR.Runner(args.image_path, args.output_path)
    runner.run()
