/*
 this is the main tester function for the classes
 */

/**
 *
 * @author aaron
 */
public class TourTester {

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Tour basicTour = new audioGuide(new selfguidedTour());
        System.out.println(basicTour.toString());
        Tour basicTour2 = new rooftopTour(new estateTour(new guidedTour()));
        System.out.println(basicTour2.toString());
        Tour basicTour3 = new glamourTour(new estateTour(new premiumTour(new guidedTour())));
        System.out.println(basicTour3.toString());
    }
}
