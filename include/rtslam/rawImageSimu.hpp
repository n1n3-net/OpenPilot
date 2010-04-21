/**
 *
 *  \file rawImageSimu.hpp
 *
 *  Header file for simulated image
 *
 * \date 14/03/2010
 * \author jmcodol@laas.fr
 *
 * \ingroup rtslam
 */

#ifndef RAWIMAGESIMU_HPP_
#define RAWIMAGESIMU_HPP_

#include "rtslam/rawAbstract.hpp"
#include "rtslam/featurePointSimu.hpp"
#include "boost/shared_ptr.hpp"

namespace jafar {
	namespace rtslam {
		using namespace std;

		class RawImageSimu;
		typedef boost::shared_ptr<RawImageSimu> rawimagesimu_ptr_t;

		/**
		 * Class of simulated image
		 * \author jmcodol
		 * \ingroup rtslam
		 */
		class RawImageSimu: public rawAbstract {

			private:
				map<int,FeaturePointSimu*> features;

			public:

				/**
				 * Constructor
				 */
				RawImageSimu() :
					rawAbstract() {
				}

				int coord;
				int app  ;

				/**
				 * Add a point-typed feature on a pixel.
				 */
				 void addFeature(const FeatureAbstract);
				 friend ostream& operator <<(ostream & s, jafar::rtslam::RawImageSimu& rawA);

			private:

		};
	}
}

#endif /* RAWIMAGESIMU_HPP_ */
