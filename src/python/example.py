from neuron_analysor import NeuronAnalysor
import argparse


class ExampleMethod(NeuronAnalysor):
    def __init__(self, image_path: str = "None", output_path: str = "None"):
        super(ExampleMethod, self).__init__(image_path, output_path)
        """
        Read Parameter
        1. Neuron Segmentation:
        self.parameters = self.read_parameter(os.path.join(self.output_path, "segmentation.yaml")
        2. Neuron Reconstruction:
        self.parameters = self.read_parameter(os.path.join(self.output_path, "reconstruction.yaml")
        3. Critical Points Detection:
        self.parameters = self.read_parameter(os.path.join(self.output_path, "detection.yaml")
        """

    def process(self, image_name: str):
        """
        This function must be overloaded for implementing your own method.
        """
        pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--image_path", "-i", type=str, default="None", help="image path")
    parser.add_argument("--output_path", "-o", type=str, default="None", help="output path")
    args = parser.parse_args()
    runner = ExampleMethod(args.image_path, args.output_path)
    runner.run()
