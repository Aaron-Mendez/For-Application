/*
    This is an addon to the decorator class that can be added
 */

/**
 *
 * @author aaron
 */
public class premiumTour extends addOn {

    public premiumTour(Tour newTour)
    {
        super(newTour);
    }
    @Override
    public String getDescription()
    {
        return tempTour.getDescription() + " A premium tour that includes many extra areas";
    }
    
    @Override
    public double getCost()
    {
        return tempTour.getCost() + 25;
    } 
    @Override
    public int getMinTimeInMinutes()
    {
        return tempTour.getMinTimeInMinutes() + 60;
    }
}
