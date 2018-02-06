#include<omp.h>
#include "mytest.h"
#include "fileOps.h"
#include<time.h>
#include<vector>
#include "classification.h"

int main()
{
	std::string logfile = "log.txt";
	::google::InitGoogleLogging(logfile.c_str());

	string model_file = "lenet_train_test.prototxt";
	string trained_file = "lenet_iter_15000.caffemodel";
	string mean_file = "mean.binaryproto";
	string label_file = "synset_words.txt";
	Classifier classifier(model_file, trained_file, mean_file, label_file);

	string file = "E://wsd//0003.jpg";

	std::cout << "---------- Prediction for "
		<< file << " ----------" << std::endl;

	cv::Mat img = cv::imread(file);
	CHECK(!img.empty()) << "Unable to decode image " << file;
	std::vector<Prediction> predictions = classifier.Classify(img);

	/* Print the top N predictions. */
	for (size_t i = 0; i < predictions.size(); ++i) {
		Prediction p = predictions[i];
		std::cout << std::fixed << std::setprecision(4) << p.second << " - \""
			<< p.first << "\"" << std::endl;
	}
	system("pause");
	return 0;
} 